    #include <bits/stdc++.h>
    #include <cmath>
    using namespace std;
    #define int long long
    #define endl "\n"
    const int MOD = 1e9+7;
     
    int max(int x, int y)
    {
        return (x>y)?x:y;
    }
    // std::vector<pair<int,int> unecces;
    void dfs(int u, vector<int> adj[], 
        vector<bool> &visited) {
        visited[u] = true;
        for (int v : adj[u])
        {
            if(!visited[v])
                dfs(v,adj,visited);
        }
    }
     
    int gcd(int a, int b)
    {
        if(a==0)
            return b;
        else
            return gcd(b%a,a);
    }
     
    void fillDepth(int parent[], int i, int depth[]) 
    {
        if (depth[i]) 
            return; 
        if (parent[i] == -1) 
        { 
            depth[i] = 1; 
            return; 
        } 
        if (depth[parent[i]] == 0) 
            fillDepth(parent, parent[i], depth);  
        depth[i] = depth[parent[i]]  + 1; 
    } 
     
    int findHeight(int parent[], int n) 
    {
        int depth[n]; 
        for (int i = 0; i < n; i++) 
            depth[i] = 0;
     
        for (int i = 0; i < n; i++) 
            fillDepth(parent, i, depth); 
     
        int ht = depth[0]; 
        for (int i=1; i<n; i++) 
            if (ht < depth[i]) 
                ht = depth[i]; 
        return ht; 
    } 
    int32_t main()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
        #endif
        
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
     
        int t;
        cin >> t;
     
        while(t--)
        {
            int n;
            cin >> n;
            int arr[n];
            int posi = 0;
            int neg = 0;
            for(int i = 0; i < n; i++)
            {
                cin >> arr[i];
                if(arr[i]>0)
                    posi++;
                if(arr[i]<0)
                    neg++;
            }
            // cout << "posi = " << posi << endl;
            sort(arr, arr+n);
            int ans = 1;
            if(posi>=5)
            {
                ans = arr[n-1]*arr[n-2]*arr[n-3]*arr[n-4]*arr[n-5];
                int temp1 = arr[0]*arr[1]*arr[2]*arr[3]*arr[n-1];
                int temp2 = arr[0]*arr[1]*arr[n-2]*arr[n-3]*arr[n-1];
                ans = max(ans, max(temp1, temp2));
            }
            else
            {
                if(posi == 3)
                {
                    ans = arr[n-1]*arr[n-2]*arr[n-3]*arr[0]*arr[1];
                    int temp1 = arr[0]*arr[1]*arr[2]*arr[3]*arr[n-1];
                    ans = max(ans, temp1);
                }
                else if(posi == 1)
                {
                    ans = arr[n-1] * arr[1]*arr[0]*arr[2]*arr[3];
                }
                else
                {
                    if(posi == 0)
                    {
                        // cout << "posi " << endl;
                        ans = arr[n-1]*arr[n-2]*arr[n-3]*arr[n-4]*arr[n-5];
                        // ans = arr[0]*arr[2]*arr[3]*arr[4]*arr[1];
                        // int j = n-1;
                        // int count = 0;
                        // while(arr[j] == 0)
                        // {
                        //     j--;
                        //     count++;
                        // }
                        // if(n-count < 5)
                        // {
                        //     ans = 0;
                        //     // cout << " YES 0 " << endl;
                        // }
                        // else
                        // {
                        //     ans = arr[j]*arr[j-1]*arr[j-2]*arr[j-3]*arr[j-4];
                        // }
                    }
                    else if(posi == 2 || posi ==4)
                    {
                        if(posi == 2)
                        {
                            ans = arr[0]*arr[1]*arr[2]*arr[3];
                            if(ans == 0)
                            {
                                ans = 0;
                            }
                            else
                                ans *= arr[n-1];
                        }
                        else
                        {
                            ans = arr[0]*arr[1];
                            if(ans == 0)
                            {
                                ans = 0;
                            }
                            else
                                ans*=arr[n-1]*arr[n-2]*arr[n-3];
                            int temp1 = arr[0]*arr[1]*arr[2]*arr[3]*arr[n-1];
                            ans = max(ans, temp1);
                        }
                    }
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
