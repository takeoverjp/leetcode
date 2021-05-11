--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

# cat 176.second-highest-salary.sql |  sqlite3 -batch
.header on
CREATE TABLE Employee (Id int, Salary int);
INSERT INTO Employee VALUES (1, 100);
INSERT INTO Employee VALUES (2, 200);
INSERT INTO Employee VALUES (3, 300);
INSERT INTO Employee VALUES (4, 300);
INSERT INTO Employee VALUES (5, 300);
INSERT INTO Employee VALUES (6, 400);
INSERT INTO Employee VALUES (7, 500);
SELECT * FROM Employee;

-- @lc code=start
# Write your MySQL query statement below

SELECT (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1) AS SecondHighestSalary;

-- @lc code=end

.quit