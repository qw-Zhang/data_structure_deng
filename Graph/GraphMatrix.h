#include "../Graph/Graph.h"
//#include "../Vector/vector.h"

template <typename Tv> 
struct Vertex{
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    int dTime, fTime;
    int parent;
    int priority;
    Vertex (Tv const& d = (Tv) 0):
        data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
        dTime(-1), fTime(-1),parent(-1), priority(__INT_MAX__) {}
};

template <typename Te> 
struct Edge{
    Te data;
    int weight;
    EStatus type;
    Edge(Te const& d,int w) :
        data(d),weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
    private:
        Vector< Vertex<Tv> > V;
        Vector< Vector<Edge<Te>* > > E;
    public:
        GraphMatrix(){
            n = 0;
            e = 0;
        }
        ~GraphMatrix(){
            for(int j  = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    delete E[j][k];
                }
            }
        }

        virtual Tv& vertex(int i){
            return V[i].data;
        }
        virtual int inDegree(int i){
            return V[i].inDegree;
        }
        virtual int outDegree(int i){
            return V[i].outDegree;
        }
        virtual int nextNbr(int i, int j){
            while((-1 < j) && (!exists(i,--j)));
            return j;
        }
        virtual int firstNbr(int i){
            return nextNbr(i,n);
        }
        

        virtual int insert(Tv const& vertex){
            for(int j = 0; j < n; j++){
                E[j].insert(NULL);
            }
            n++;

            E.insert(Vector< Edge<Te>* >(n,n,NULL));

            return V.insert(Vertex<Tv>(vertex));
        }

        virtual Tv remove(int i){
            for(int j = 0; j < n;j++){
                if(exists(i,j)){
                    delete E[i][j];
                    V[j].inDegree--;
                }
            }
            E.remove(i);
            n--;

            for(int j = 0;j < n;j++){
                if(exists(j,i)){
                    delete E[j].remove(i);
                    V[j].outDegree--;
                }
            }
            Tv vBak = vertex(i);
            V.remove(i);
            return vBak;
        }

        virtual bool exists(int i,int j){
            return (0 <= i)&&(i < n) && (0 <= j) && (j < n)
                   && E[i][j] != NULL;
        }
        virtual Te& edge(int i,int j){
            return E[i][j]->data;
        }
        virtual EStatus& type(int i, int j){
            return E[i][j]->type;
        }
        virtual int& weight(int i,int j){
            return E[i][j]->weight;
        }

        virtual void insert(Te const& edge, int w, int i, int j) {
            if(exists(i,j)){
                return ;
            }
            E[i][j] = new Edge<Te>(edge,w);
            e++;
            V[i].outDegree++;
            V[j].inDegree++;
        }
        virtual Te remove(int i,int j) {
            Te eBak = edge(i,j);
            delete E[i][j];
            E[i][j] = NULL;
            e--;
            V[i].outDegree--;
            V[j].inDegree--;
            return eBak;
        }

};