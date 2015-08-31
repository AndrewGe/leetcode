mplement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 


class Solution {
public:
    int myAtoi(string str) {
       
         
    	if ( str.find_first_of("0123456789") ==string::npos )
    	    return 0;
    	   
        int i = str.find_first_not_of(" \t");
		int sign = 1;
		if(str[i] == '-')
		{
			sign = -1;
			++i;
		}
		else if(str[i] == '+')
		{
			++i;
		}

		long long res = 0;
		//bool first=true;
    	while(str[i] != '\0')
    	{
    		if(str[i] >= '0' && str[i] <= '9')
    		{
    	/*		if (first){
    			    if (str[i]=='0') return 0;
    			    else first=false;
    			}
    	*/		    
    			    
    			res = res * 10 + (str[i] - '0');
                ++i;
    			if(res > INT_MAX)
    			{
    				return sign == -1 ? INT_MIN : INT_MAX;
    			}
    		}
    		// "   +0 123" should output 0 while or "0123" should output 123
    		/*else if (str[i] == ' ' || str[i] == '\t'  ) { 
    		    i++;
    		    continue;
    		    
    		}
    		*/
    		else
    		{
    			break;
    		}

    		
    	}

		return sign * res;  
    }
};
