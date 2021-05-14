--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

# cat 183.customers-who-never-order.sql |  sqlite3 -batch
.header on
CREATE TABLE Customers (Id int, Name string);
INSERT INTO Customers VALUES (1, "Joe");
INSERT INTO Customers VALUES (2, "Henry");
INSERT INTO Customers VALUES (3, "Sam");
INSERT INTO Customers VALUES (4, "Max");
SELECT * FROM Customers;

CREATE TABLE Orders (Id int, CustomerId int);
INSERT INTO Orders VALUES (1, 3);
INSERT INTO Orders VALUES (2, 1);
SELECT * FROM Orders;

-- @lc code=start
# Write your MySQL query statement below

SELECT Name AS Customers FROM Customers WHERE Id NOT IN (SELECT CustomerId FROM Orders);

-- @lc code=end

.quit