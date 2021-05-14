diff --git a/CodeJam/Main.cpp b/examples/2020/KS_C/A/Main.cpp
index fad3e96..355b3de 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2020/KS_C/A/Main.cpp
@@ -1025,11 +1025,29 @@ void init(){
     cin >> T;
 }
 
+ll N, K;
+v(ll) Ai;
+
 void readInput(){
+    cin >> N >> K;
+    Ai.resize(N);
+    forn(i, N) cin >> Ai[i];
 }
 
 // write to COMM_TYPE result
 void calcFunction() {
+    result = 0;
+    bool start_cd = false;
+    forn(i, N){
+        if(start_cd){
+            if(Ai[i] != Ai[i-1]-1) start_cd = false;
+        }
+        if(start_cd && Ai[i] == 1){
+            start_cd = false;
+            result++;
+        }
+        if(Ai[i] == K) start_cd = true;
+    }
 }
 
 } // namespace task
