class Solution {
    public int numTeams(int[] rating) {
        int res = 0;
        int n = rating.length;

        for(int i =0 ;i <n ; i++){
            int leftLess = 0;
            int leftGreater = 0;
            int rightLess = 0;
            int rightGreater = 0;

            for(int j = 0; j < i; j++){
                if(rating[j] < rating[i]){
                    leftLess++;
                }else if(rating[j] > rating[i]){
                    leftGreater++;
                }
            }

            for(int j = i+1; j < n; j++){
                if(rating[j] < rating[i]){
                    rightLess++;
                }else if(rating[j] > rating[i]){
                    rightGreater++;
                }
            }

            res += leftLess * rightGreater + leftGreater * rightLess;
        }
        
       
       return res; 
    }
}