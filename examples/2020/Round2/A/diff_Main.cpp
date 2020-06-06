diff --git a/CodeJam/Main.cpp b/examples/2020/Round2/A/Main.cpp
index c7ccb3b..7d7d698 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2020/Round2/A/Main.cpp
@@ -4,7 +4,7 @@
 // #define IA_MODE        //remove comment on this line, to activate interactive problem mode
 #define IA_ERROR_CODE "ERROR"
 // #define XY_NOTATION    //remove commment on this line, to activate xy notation on complex numbers
-#define COMM_TYPE ll
+#define COMM_TYPE str
 
 // The maintained and empty code template can be found at:
 // https://github.com/DavidS3141/CodeJamTemplate
@@ -1013,11 +1013,43 @@ namespace task {
 void init(){
 }
 
+ll L, R;
+
 void readInput(){
+    cin >> L >> R;
 }
 
 // write to COMM_TYPE result
 void calcFunction() {
+    ll diff = abs(L - R);
+    llog("diff", diff);
+    ll n = lower_bound_function<ll,bool>(true, [&](ll c){return diff<c*(c+1)/2;}, sqrtl(INF))-1;
+    if(diff==0) n=0;
+    llog("initial n from one pile", n);
+    ll take = n*(n+1)/2;
+    if(R>L){
+        R-=take;
+    } else
+        L-=take;
+    bool left_first = L>=R;
+    llog("left first", left_first);
+    ll nL = lower_bound_function<ll,bool>(true, [&](ll c){return L<(n+2-left_first)*(c+1) + c*(c+1);}, sqrtl(INF))-1;
+    llog("nL", nL);
+    ll takeL = (n+2-left_first)*(nL+1)+nL*(nL+1);
+    nL = n+2-left_first + 2 * (nL);
+    llog("nL", nL);
+    ll nR = lower_bound_function<ll,bool>(true, [&](ll c){return R<(n+1+left_first)*(c+1) + c*(c+1);}, sqrtl(INF))-1;
+    llog("nR", nR);
+    ll takeR = (n+1+left_first)*(nR+1)+nR*(nR+1);
+    nR = n+1+left_first + 2 * (nR);
+    llog("nR", nR);
+    n = max(n, max(nR, nL));
+    R-=takeR;
+    L-=takeL;
+
+    sstr res;
+    res << n << " " << L << " " << R;
+    result = res.str();
 }
 
 } // namespace task
