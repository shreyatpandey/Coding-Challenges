bool isCyclic(int N,vector<vector<int>>AdjList)
{
  queue<int>Q;
  vector<int>Indegree(N,0);
  for(int i=0;i<N;i++)
  {
  
  for(auto it:AdjList[i)
  {
    Indegree[it]++;
    }
   }
   for(int i=0;i<N;i++)
   {
    if(Indegree[i] == 0)
    {
      Q.push(i);
    }
   }
  int Cnt = 0;
  while(q.size()
  {
    int node = Q.front();
    Q.pop();
    Cnt += 1;
    for(auto it:AdjList[node])
    {
      Indegree[it]--;
      if ( Indegree[it] == 0 )
      {
        Q.push(it);
      }
    }
   }
  if ( Cnt == N )
    return false;
    
    return true;
  }

