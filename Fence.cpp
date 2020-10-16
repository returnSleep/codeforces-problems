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
     
    const int MAX = 20000; 
     
    string f[MAX] = {"0"}; 
    string findSum(string str1, string str2) 
    { 
        
        if (str1.length() > str2.length()) 
            swap(str1, str2); 
      
        string str = ""; 
      
        int n1 = str1.length(), n2 = str2.length(); 
        int diff = n2 - n1; 
      
        int carry = 0; 
      
        for (int i=n1-1; i>=0; i--) 
        { 
            int sum = ((str1[i]-'0') + 
                       (str2[i+diff]-'0') + 
                       carry); 
            str.push_back(sum%10 + '0'); 
            carry = sum/10; 
        } 
      
        for (int i=n2-n1-1; i>=0; i--) 
        { 
            int sum = ((str2[i]-'0')+carry); 
            str.push_back(sum%10 + '0'); 
            carry = sum/10; 
        } 
      
        if (carry) 
            str.push_back(carry+'0'); 
      
        reverse(str.begin(), str.end()); 
      
        return str; 
    } 
     
    string fib(int n) 
    { 
        if (n == 0) 
            return "0"; 
        if (n == 1 || n == 2) 
            return (f[n] = "1"); 
     
        string s1 = f[n-1];
        string s2 = f[n-2];
        f[n] = findSum(s1,s2);
      
        return f[n]; 
    } 
    void precal()
    {
        for(int i =1;i<=MAX;i++)
        {
            fib(i);
        }
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
        // precal();
        int t;
        cin >> t;
        // cout << std::hex << fib(t) << endl;
        while(t--)
        {
            int a[3];
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a+3);
            int dif = a[2]-a[1];
            int ans = sqrt(dif*dif+a[0]*a[0]);
            cout << ans+1 << endl;
        }
        return 0;
    }
