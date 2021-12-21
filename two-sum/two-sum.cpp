//                         pair.push_back(j);
//                         return pair;
//                     }
//                 }
//             }
//             // If start < target => check availability using for loop with j, if it is, return, else incremeting i
//             else if(start < target){
//                 int remain = target - start;
//                 for(int j=i+1; j < nums.size(); j++){
//                     if(nums[j] == remain){
//                         pair.push_back(i);
//                         pair.push_back(j);
//                         cout << "something happen here" << endl;
//                         return pair; // Why this does not return anything?
//                     }
//                 }
//             }
//         }
//         return fake;
//     }
// };
​
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
        }
        return temp; // if nothing then return temp as nothing, but this not gonna happen
    }
};
​
​
/**
    - not using same element twice
    - Have exactly 1 solution
    - Input: Array of number and the target
    - Output: Pair of two number in the location of the array
    
    ==== Thinking
    Using for loop, check number, if the number is larger or equal to the target then go to the next number
    Deduce to get the second number, trace thru the rest using for loop, if there is none, then move to the next number
    Remember to save the position
**/
