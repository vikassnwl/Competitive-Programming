class Solution {
  public:
  
  int orientation(int p1[], int p2[], int p3[]){
      int val = (p2[1]-p1[1])*(p3[0]-p2[0])-(p3[1]-p2[1])*(p2[0]-p1[0]);
      if(val==0) return 0;
      if(val<0) return 1;
      return 2;
  }
  
  bool validProjection(int a, int b, int c, int d){
      if(a>b) swap(a, b);
      if(c>d) swap(c, d);
      return max(a, c) <= min(b, d);
  }
  
    int doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);
        
        if(o1!=o2 and o3!=o4) return 1;
        if(o1==0 and o4==0){
            if(validProjection(p1[0], q1[0], p2[0], q2[0]) and validProjection(p1[1], q1[1], p2[1], q2[1]))
                return 1;
        }
        return 0;
    }
};
