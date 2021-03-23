/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (const auto employee : employees) {
            if (employee->id == id) {
                int sum = employee->importance;
                for (const auto sub_id : employee->subordinates) {
                    sum += getImportance(employees, sub_id);
                }
                return sum;
            }
        }
        return 0;
    }
};
// @lc code=end

