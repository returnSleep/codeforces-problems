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
    string fun(string ans, string s, int n, int k, int c0, int c1, int cQ)
    {
        for(int i=k;i<n;i++)
            {
                if(s[i] == '1')
                    c1++;
                else if(s[i] == '0')
                    c0++;
                
                if(s[i-k] == '1')
                    c1--;
                else if(s[i-k] == '0')
                    c0--;
                  
                // cout << c0-c1 << endl;
                if(s[i] == '?')
                {
                    if(s[i-k] == '1')
                    {
                        s[i] = '1';
                        c1= 0;
                        c0 = 0;
     
                    }
                    else if(s[i-k] == '0')
                    {
                        s[i] = '0';
                        c1= 0;
                        c0 = 0;
     
                    }
                    else
                    {
                        ans = "NO";
                        break;
                    }
                }
                if(c1 != c0)
                {
                    int diff = abs(c1-c0);
                    if(diff>cQ)
                    {
                        ans = "NO";
                        break;
                    }
                }
            }
            return ans;
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
        // int test_case = 1;
        while(t--)
        {
            int n, k;
            cin >> n >> k;
            string s;
            cin >> s;
            int ans;
            // if(s[0] == 'W')
            //     ans++;
            int win = 0, los=0;
            int winStreak = 0;
            int i = 0;
            vector<int> losIndex;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == 'W')
                {
                    win++;
                    if(i == 0 || s[i-1] == 'L')
                        winStreak++;
                }
                else
                {
                    los++;
                    if( i == 0 || s[i-1] == 'W')
                        losIndex.push_back(0);
                    losIndex.back()++;
                }
     
            }
            if(k>=los)
            {
                ans = 2*n-1;
                cout << ans << endl;
                continue;
            }
            else if(win == 0 && k == 0)
            {
                ans = 0;
                cout << ans << endl;
                continue;
            }
            else if(win == 0 && k>0)
            {
                ans = 2*k-1;
                cout << ans << endl;
                continue;
            }
            if(s[0] == 'L')
                losIndex[0] = 1e8;
            if(s[n-1] == 'L')
                losIndex.back() = 1e8;
            sort(losIndex.begin(), losIndex.end());
            win+=k;
            for(int ls : losIndex)
            {
                if(ls> k )
                    break;
                k-=ls;
                winStreak--;
            }
            ans = (2*win-winStreak);
            cout << ans << endl;
        }
        return 0;
    }
