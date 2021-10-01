int rightmostNonZeroDigit(int N, int A[]){
        int c5 = 0;
        for(int i=0; i<N; i++){
            while(A[i]%5==0 and A[i]!=0){
                A[i] /= 5; // removing 5's from all the numbers
                c5++; // incrementing count of 5's
            }
        }
        
        for(int i=0; i<N; i++){
            while(c5 and A[i]%2==0 and A[i]!=0){
                A[i] /= 2; // removing 2's from all the numbers
                c5--; // decrementing count of 5's because 2*5=10
            }
        }

	// multiplying the numbers and taking the last digit
        int res = 1;
        for(int i=0; i<N; i++){
            res = res*A[i]%10;
        }
        
        if(c5){ 
	    // count of 5 exist so multiply by 5 because 5^n(here n is the count of 5) contains 5 as last digit
	    // and also 2 doesn't exist in factor of res that's why we won't get 0 as remainder in below operation
            res = res*5%10;
        }
        if(res){
            return res;
        }
        return -1;
}
