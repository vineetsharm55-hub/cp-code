class Solution {
public:
    string addStrings(string num1, string num2) {
         int i=num1.size()-1;
         int j=num2.size()-1;

         int carry=0;
         int sum=0;
         string output="";
         while(i>=0||j>=0){
            int val1=(i>=0)? num1[i]- '0':0;
            int val2=(j>=0)? num2[j]- '0':0;
            sum=val1+val2+carry;
            carry=sum/10;
            sum=sum%10;
            output+=(sum+'0');
            i--;
            j--;
         }
         if(carry>0){
            output+=(carry+'0');
         }
         reverse(output.begin(), output.end());
         return output;
        
    }
};