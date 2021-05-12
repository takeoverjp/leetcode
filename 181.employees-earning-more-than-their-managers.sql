--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

# cat 181.employees-earning-more-than-their-managers.sql |  sqlite3 -batch
.header on
CREATE TABLE Employee (Id int, Name string, Salary int, ManagerId int);
INSERT INTO Employee VALUES (1, "Joe", 70000, 3);
INSERT INTO Employee VALUES (2, "Henry", 80000, 4);
INSERT INTO Employee VALUES (3, "Sam", 60000, NULL);
INSERT INTO Employee VALUES (4, "Max", 90000, NULL);
SELECT * FROM Employee;

-- @lc code=start
# Write your MySQL query statement below

SELECT A.Name AS Employee
  FROM Employee AS A
  INNER JOIN Employee AS B
  ON A.ManagerId = B.Id
  WHERE A.Salary > B.Salary;

-- @lc code=end

.quit