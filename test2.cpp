                 /* **                      树                 *** */
////树：
///*
// 存储方式：
//    1：双亲表示法（该节点知道自己，并知道父结点的位置。但是不知道自己结点的子节点（要改进））
//    2：孩子表示法（数组+链表的存储方式，PPT树（p10））
//*/
////2：孩子表示法代码：
//
////孩子结点的链表:
//typedef struct CNod{
//    int pos;//该子节点的下标
//    struct CNod* next;//指向下一个子结点
//}*ChildNod;
//
////表头结构：
//typedef struct {
//    char data;//结点数据域
//    int parent;//结点的父结点的下标
//    ChildNod child;//结点的第一个孩子  ？？？指针
//}ThNod;
//
////树结构
//typedef struct {
//    ThNod nods[100];//树的结点
//    int r,n;//r:结点的位置，n:结点的数量
//};


                            /*           图            */
//图：
/*1：存储方法：邻接矩阵，邻接表，十字链表
 *
 *
 *
*/

//邻接表存储:https://zhuanlan.zhihu.com/p/618361957
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int head[100],ver[100],nxt[100],edge[100];
     int tot=0;
     int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){//几个数组想了4,5天，很绕。
          int x,y,z;
           cin>>x>>y>>z;
           ver[++tot]=y;
           edge[tot]=z;
           nxt[tot]=head[x];
           head[x]=tot;
      }

        int a;
          cin>>a;
       //遍历a顶点的所有出边
        for(int i=head[a];i;i=nxt[i]){
            int j=ver[i],w=edge[i];//j终点，w权
             cout<<j<<" "<<w<<endl;
        }
    return 0;
}*/


//1:图的存储（洛谷）：（邻接矩阵+邻接表实现）
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int M[N][N],r[N];
vector<int>g[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        M[a][b]=M[b][a]=1;
        g[a].push_back(b);
        g[b].push_back(a);
        r[a]++;
        r[b]++;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<M[i][j]<<" \n"[j==n];
        }
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
        cout<<r[i]<<" ";
        for(auto j:g[i]){
            cout<<j<<" ";
      }
        cout<<endl;
    }
    return 0;
}*/


//2:图的遍历（洛谷）邻接表+dfs遍历 ，技巧：反向邻接表
/*
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1e5+9;

vector<int>G[N];
int vis[N];//作用：标记访问+存储 i顶点能到达最大的编号顶点

void dfs(int x,int d){
    if(vis[x]){
        return;
    }
    vis[x]=d;
     for(int i=0;i<G[x].size();i++){
         dfs(G[x][i],d);
     }
}

int main()
{
    int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b;
           cin>>a>>b;
            G[b].push_back(a);
      }

       for(int i=n;i;i--){
           dfs(i,i);
       }
       for(int i=1;i<=n;i++){
           cout<<vis[i]<<" ";
       }
    return 0;
}*/


//3:拓扑排序/家谱树
/*#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int N=1000009;

vector<int> G[N];//邻接矩阵
queue<int> q;
int R[N];//顶点的入度数

void solve(){
     while(!q.empty()){
         int t=q.front();
          q.pop();
          cout<<t<<" ";
          //遍历该顶点的后代，G[t]
          for(auto x:G[t]){
              R[x]--;
              if(R[x]==0){
                  q.push(x);
              }
          }
     }
}

int main()
{
    int n;
     cin>>n;
      for(int i=1;i<=n;i++){
          int a;
          while(cin>>a&&a){
             G[i].push_back(a);
             R[a]++;
          }
      }

       for(int i=1;i<=n;i++){
           if(R[i]==0){
               q.push(i);//入度==0的顶点入队
           }
       }
       solve();
    return 0;
}*/



//4:Count Connected Components
//dfs遍历
/*#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=109;

vector<int>G[N];
int vis[N];
int ans=0;

void dfs(int x){
    if(vis[x]==1){
        return;
    }
    vis[x]=1;
    for(auto i:G[x]){
        dfs(i);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}*/


//5:查找文献（洛谷）
//图的遍历：dfs，bfs，（优先输出小的元素，排序(set容器解决)）
/*#include<bits/stdc++.h>
#include<set>
#include<queue>
using namespace std;
const int N=1e6+9;

int vis[N];
set<int>G[N];
queue<int>q;

void dfs(int x){
    if(vis[x]==1){return;}
    vis[x]=1;
    cout<<x<<" ";
    for(auto it:G[x]){
        if(!vis[it]){
          dfs(it);
        }
    }
}

void bfs(){
    q.push(1);
     vis[1]=1;//ERROR
    while(!q.empty()){
        int x=q.front();
        cout<<x<<" ";
        for(auto a:G[x]){
            if(!vis[a]){
                vis[a]=1;
                q.push(a);
            }
        }
        q.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        G[a].insert(b);
    }

    dfs(1);
    cout<<endl;
    memset(vis,0,sizeof(vis));

    bfs();
    return 0;
}*/


//WA!!!
//6:Valid BFS?
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;

int vis[N];
int result1[N];
int result2[N];
int k=0;
vector<int>G[N];
queue<int>q;

void bfs(){
      q.push(1);
       vis[1]=1;
     while(!q.empty()){
         int x=q.front();
         result1[k++]=x;
         q.pop();
         for(auto a:G[x]){
             if(!vis[a]){
                 vis[a]=1;
                 q.push(a);
             }
         }
     }
}

int main()
{
    int n;
     cin>>n;

        for(int i=1;i<n;i++){
            int a,b;
             cin>>a>>b;
              G[a].push_back(b);
              G[b].push_back(a);
        }

     for(int i=0;i<n;i++){
         cin>>result2[i];
     }

        bfs();
       int flag=0;
         for(int i=0;i<n;i++){
             if(result1[i]!=result2[i]){
                 flag=1;
                 break;
             }
         }

          if(!flag){
              cout<<"Yes"<<endl;
          }
          else{
              cout<<"No"<<endl;
          }
    return 0;
}*/



//dijkstra算法(图中起点到终点的最短路径):
/*#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[100];//存图： first为值???，second为点
vector<int>vis(100,0),dis(100,INT_MAX);

void dijkstra(){
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
     priority_queue<pair<int,int>>q;
      q.push({0,1});
         dis[1]=0;
       while(!q.empty()){
           int u=q.top().second;//当前图中距离起点最小距离的点
            q.pop();
            if(vis[u]){
                continue;
            }
             vis[u]=1;
            for(auto [x,y]:v[u]){
                if(dis[y]>dis[u]+x){
                    dis[y]=dis[u]+x;
                    q.push({-dis[y],y});
                }
            }
       }
}

int main()
{
    int n,m;
     cin>>n>>m;
      int end=n;
      while(m--){
          int a,b,len;
           cin>>a>>b>>len;
            v[a].push_back({len,b});
            v[b].push_back({len,a});
      }
           dijkstra();
        cout<<dis[end]<<endl;
    return 0;
}*/



//7:Dijkstra(输出通过的路径)
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;//???
ll d[N];//记录路径
ll R[N];
vector<pair<ll,ll>>G[N];
vector<ll>vis(N,0),dis(N,INF);
priority_queue<pair<ll,ll>>q;

void dijkstra(){
    q.push({0,1});//first距离，second结点
      dis[1]=0;
      while(!q.empty()){
          int t=q.top().second;
           q.pop();
            if(vis[t]){
                continue;
            }
             vis[t]=1;
            for(auto[x,y]:G[t]){
                if(dis[y]>dis[t]+x){
                    dis[y]=dis[t]+x;
                      d[y]=t;
                     q.push({-dis[y],y});
                }
            }
      }
}

int main()
{
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
         int n,m;
       cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b,len;
           cin>>a>>b>>len;
           G[a].push_back({len,b});
           G[b].push_back({len,a});
      }
        dijkstra();
          vector<int>path;
         if(dis[n]==INF){
             cout<<-1<<'\n';
         }
         else{
              while(n){
                  path.push_back(n);
                  n=d[n];
              }
             int len=path.size();
             for(int i=len-1;i>=0;i--){
                 cout<<path[i]<<" ";
             }
             cout<<'\n';
         }

    return 0;
}*/



//8: Ordering Tasks
//拓扑排序
/*#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int R[N];//各顶点的入度
queue<int>q;
vector<int>G[N];

void solve(){
     while(!q.empty()){
         int t=q.front();
          cout<<t<<" ";
          q.pop();
          for(auto x:G[t]){
              R[x]--;
               if(R[x]==0){
                   q.push(x);
               }
          }
     }
     cout<<endl;
}

int main()
{
    int n,m;
      while(cin>>n>>m){
          memset(G,0,sizeof(G));
           if(n==0&&m==0){ break;}
          for(int i=0;i<m;i++){
              int a,b;
               cin>>a>>b;
                G[a].push_back(b);
                 R[b]++;
          }

            for(int i=1;i<=n;i++){
                if(R[i]==0){
                    q.push(i);
                }
            }
               solve();
      }
    return 0;
}*/


//Dijkstra:
//无向图
//9:
/*#include<bits/stdc++.h>
using namespace std;
const int N=20009;

vector<pair<int,int>>G[N];//first值，second结点
vector<int>vis(N,0),dis(N,INT_MAX);
priority_queue<pair<int,int>>q;

void solve(){

    q.push({0,1});
         dis[1]=0;
       while(!q.empty()){
           int t=q.top().second;
             q.pop();
            if(vis[t]==1){
                continue;
            }
             vis[t]=1;
             for(auto[x,y]:G[t]){
                 if(dis[y]>dis[t]+x){
                     dis[y]=dis[t]+x;
                      q.push({-dis[y],y});
                 }
             }
       }
}

int main()
{
    int n,m;
      while(cin>>n>>m)
      {
           fill(vis.begin(),vis.end(),0);
           fill(dis.begin(),dis.end(),INT_MAX);
            memset(G,0,sizeof(G));
          if(n==0&&m==0){ break;}
          for(int i=1;i<=m;i++){
              int a,b,len;
                cin>>a>>b>>len;
                 G[a].push_back({len,b});
                  G[b].push_back({len,a});
          }
           solve();
          cout<<dis[n]<<endl;
      }
    return 0;
}*/



//10：Floyd算法（洛谷，板子题）：
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=109;

ll G[N][N];
int n,m;

void floyd(){
    for(int k=1;k<=n;k++){//k:中转站
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               if(G[i][j]>G[i][k]+G[k][j]){
                   G[i][j]=G[i][k]+G[k][j];
               }
           }
       }
    }
}

int main()
{

      cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                G[i][j]=0;
            }
            else{
                G[i][j]=INT_MAX;
            }
        }
    }

       for(int i=1;i<=m;i++){
           ll a,b,len;
            cin>>a>>b>>len;
            G[a][b]=min(G[a][b],len);
            G[b][a]=min(G[b][a],len);
       }


        floyd();

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}*/

//11: 单源最短路径（弱化版）(洛谷)
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;

vector<pair<int,int>>G[N];//first值
vector<int>vis(N,0),dis(N,INT_MAX);
priority_queue<pair<int,int>>q;
int n,m,s;

void dij(){
    q.push({0,s});
      dis[s]=0;
        while(!q.empty()){
            int t=q.top().second;
             q.pop();
             if(vis[t]){
                 continue;
             }
              vis[t]=1;
              for(auto[x,y]:G[t]){
                  if(dis[y]>dis[t]+x){
                      dis[y]=dis[t]+x;
                       q.push({-dis[y],y});
                  }
              }
        }
}

int main()
{

      cin>>n>>m>>s;//s为起点
       for(int i=1;i<=m;i++){
           int u,v,w;
            cin>>u>>v>>w;
              G[u].push_back({w,v});
       }

         dij();
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
    return 0;
}*/


//12:最短路计数:dij再dfs？(洛谷)
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;

vector<pair<int,int>>G[N];
vector<int>vis(N,0),dis(N,INT_MAX);
priority_queue<pair<int,int>>q;
int cnt=0;

void dij(){
    q.push({0,1});
      dis[1]=0;
        while(!q.empty()){
            int t=q.top().second;
             q.pop();
             if(vis[t]){
                 continue;
             }
              vis[t]=1;
              for(auto[x,y]:G[t]){
                  if(dis[y]>dis[t]+x){
                      dis[y]=dis[t]+x;
                       q.push({-dis[y],y});
                  }
              }
        }
}

void dfs(int x,int end){//当前点，终点
    if(vis[x]){
        return;
    }
    vis[x]=1;

     if(x==end && ){//&&走的路径==最短路径

     }

     for(int i=1;i<=G[x].size();i++){
         dfs(G[x][i],end);
     }
}

int main()
{
    int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b;
           cin>>a>>b;
           G[a].push_back({1,b});
           G[b].push_back({1,a});
      }

         dij();
        cout<<1<<" ";
       for(int i=2;i<=n;i++){
           fill(vis.begin(),vis.end(),0);
            dfs(1,n);//起点，终点
       }
    return 0;
}*/



//13:寻找道路：（洛谷）:反向搜索（！！！）
//反向建图，orZ
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;

int vis[N];
int can[N];//标记能到达终点的点
int ri[N];//标记合规点
int dis[N];//记录合规点的最短路径,并起到vis作用
vector<int>zG[N],fG[N];
queue<int>q;

int main()
{
    int n,m,s,t;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b;
           cin>>a>>b;//有向图
            zG[a].push_back(b);
            fG[b].push_back(a);//反向建图
      }
      cin>>s>>t;
      //反向bfs，找出能到达终点的点
         q.push(t);
          can[t]=1;
        while(!q.empty()){
            int temp=q.front();
             q.pop();
              for(int i=fG[temp].size()-1;i>=0;i--){
                  int to=fG[temp][i];//to:temp点 的有向点
                   if(!can[to]){
                       q.push(to);
                       can[to]=1;//标记：能到达终点
                   }
              }
        }
         if(!can[s]){
             cout<<"-1"<<endl;
              return 0;
         }

        //遍历能到达终点的顶点，若该点有不能到达终点的点，则删除该顶点
           for(int i=1;i<=n;i++){
               if(can[i]){
                    ri[i]=1;
                   for(int j=zG[i].size()-1;j>=0;j--){
                       int temp=zG[i][j];
                        if(!can[temp]){
                             ri[i]=0;
                            break;
                        }
                   }
               }
           }

    if(!ri[s])			            //这里需要特殊判定一下起点是否满足条件
    {
        cout<<"-1";
        return 0;
    }
       //正向bfs，遍历合规点，求最短路径
        dis[s]=1;
        q.push(s);
         while(!q.empty()){
             int temp=q.front();
              q.pop();
               if(temp==t){
                   cout<<dis[temp]-1<<endl;//因为起点dis[]+1了的
                    return 0;
               }
              for(int i=zG[temp].size()-1;i>=0;i--){
                  int to=zG[temp][i];
                  if(!dis[to]&&ri[to]){
                      dis[to]=dis[temp]+1;
                      q.push(to);
                  }
              }
         }

           cout<<"-1"<<endl;
    return 0;
}*/



//14:最短路计数（洛谷）（邻接表存储+最短路的条数）
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
const int Mod=100003;
int ans[N];//记录路径数

vector<pair<int,int>>G[N];//first:值
vector<int>dis(N,INT_MAX),vis(N,0);
priority_queue<pair<int,int>>q;

void dig(){
     ans[1]=1;
     dis[1]=0;
      q.push({0,1});
       while(!q.empty()){
           int t=q.top().second;
            q.pop();
            if(vis[t]){
                continue;
            }
             vis[t]=1;
             for(auto[x,y]:G[t]){
                 if(dis[y]>dis[t]+1){
                     dis[y]=dis[t]+1;
                      ans[y]=ans[t];
                       q.push({-dis[y],y});
                 }
                 else if(dis[y]==dis[t]+1){
                     ans[y]+=ans[t];
                     ans[y]%=Mod;//
                 }
             }
       }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int x,y;
           cin>>x>>y;
            G[x].push_back({1,y});
            G[y].push_back({1,x});
      }

       dig();
       for(int i=1;i<=n;i++){
           cout<<ans[i]<<'\n';
       }
    return 0;
}*/

