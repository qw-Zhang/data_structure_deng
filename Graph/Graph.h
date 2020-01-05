typedef enum{UNDISCOVERED, DISCOVERED, VISITED} VStatus;
typedef enum{UNDETERMINED, TRWW, CROSS, FORWARD, BACKWARD} EStatus;

template <typename Tv,typename Te>
class Graph{
    private:
        void reset(){
            for(int i = 0; i < n;i++){
                V_status(i) = UNDISCOVERED;
                dTime(i) = fTime(i) = -1;
                parent(i) = -1;
                priority(i) = __INT_MAX__;
                for(int j = 0; j < n; j++){
                    if(exists(i,j)){
                        E_status(i,j) = UNDETERMINED;
                    }
                }
            }
        }

        void BFS(int, int&);
        void DFS(int, int&);
        void BCC(int, int&, Stack<int>&);
        bool TSort(int , int&, Stack<Tv>*);
        template <typename PU> void PFS(int, PU);

    public:
        int n;
        virtual Tv remove( int ) = 0;
        virtual Tv& vertex( int ) = 0;
        virtual int inDegree( int ) = 0;
        virtual int outDegree( int ) = 0;
        virtual int firstNbr( int ) = 0;
        virtual int nextNbr(int , int ) = 0;
        virtual VStatus& status ( int ) = 0;
        virtual int& dTime( int ) = 0;
        virtual int& fTime( int ) = 0;
        virtual int& parent( int ) = 0;
        virtual int& priority( int ) = 0;

        int e;
        virtual bool exists(int , int ) = 0;
        virtual void insert(Te const&,int , int , int ) = 0;
        virtual Te remove(int , int ) = 0;
        virtual EStatus& type(int , int ) = 0;
        virtual Te& edge(int , int ) = 0;
        virtual int& weight(int , int ) = 0;

        void bfs(int);
        void dfs(int);
        void bcc(int);
        Stack<Tv>* tSort(int);
        void prim(int);
        void dijkstra(int);
        template <typename PU> void pfs(int, PU);

};