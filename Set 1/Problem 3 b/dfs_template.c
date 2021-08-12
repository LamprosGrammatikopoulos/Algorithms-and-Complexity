#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// define the new structure
struct graph {
  int n;     // number of vertices
  int m;     // number of edges
  int **adj; // adjacency matrix
  int *ideg; // the input degree
  int *odeg; // the output degree
};

typedef struct graph Graph;


// our global graph (to keep things simple)
Graph g;


// available functions
void init_graph();
void print_graph();
void clear_graph();
void dfs();  
void dfs_visit(int); 


// -----------------------
// initialises the graph
// -----------------------
void init_graph()
{
   int n, m;
   int u, v;
   int i, j;

   // get user's input -- number of vertices
   // TODO: get n from the user	
   // TODO: ensure that n >> 0	
   g.n = n;

   // allocate memory for adjacency matrix
   g.adj = (int **) malloc(g.n * sizeof(int *));

   for (i=0; i<g.n; i++)
      g.adj[i] = (int *) malloc(g.n * sizeof(int));

   // safe initialisation
   for (i=0; i<g.n; i++)
      for (j=0; j<g.n; j++)
         g.adj[i][j] = 0;

   // get user's input -- number of edges
   // TODO: get m from the user	
   // TODO: ensure that m >> 0	
   g.m = m;

   // get user's input -- graph edges
   for (i=0; i<g.m; i++) {
      // TODO: get u (source), v (destination)
      // TODO: ensure that 1 <= u, v <= g.n

      g.adj[u-1][v-1] = 1;
   }

   // allocate memory for degree matrices
   g.ideg = (int *) malloc(g.n * sizeof(int));
   g.odeg = (int *) malloc(g.n * sizeof(int));

   // safe initialisation
   for (i=0; i<g.n; i++) {
      g.ideg[i] = 0;
      g.odeg[i] = 0;
   }

   for (i=0; i<g.n; i++)
      for (j=0; j<g.n; j++)
         if (g.adj[i][j] == 1) {
            g.ideg[j] += 1;
            g.odeg[i] += 1;
         }

   // TODO: ensure that the degrees sum into g.m
   // TODO: for both matrices: g.ideg and g.odeg
   // TODO: print an error message if needed ...
}


// -----------------------
// print the graph
// -----------------------
void print_graph()
{
   // TODO: print the graph
}


// -----------------------
// releases graph's memory
// -----------------------
void clear_graph()
{
   for (int i=0; i<g.n; i++)
      free(g.adj[i]);

   free(g.adj);
   free(g.ideg);
   free(g.odeg);

   g.n = 0;
   g.m = 0;
}


// -----------------------
// the main DFS algorithm
// -----------------------
void dfs()
{
   // TODO: check the slides
   // TODO: also prints info
}


// -----------------------
// recursive DFS procedure
// -----------------------
void dfs_visit(int u) 
{
   // TODO: check the slides
   // TODO: also prints info
}


// -----------------------
// our main function
// -----------------------
int main() 
{
   init_graph();
   print_graph();

   dfs();

   clear_graph();

   return 0;
}

