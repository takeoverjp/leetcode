--
-- @lc app=leetcode id=196 lang=mysql
--
-- [196] Delete Duplicate Emails
--

# cat 196.delete-duplicate-emails.sql |  sqlite3 -batch
.header on
CREATE TABLE Person (Id int, Email string);
INSERT INTO Person VALUES (1, "john@example.com");
INSERT INTO Person VALUES (2, "bob@example.com");
INSERT INTO Person VALUES (3, "john@example.com");
SELECT * FROM Person;
SELECT MIN(Id) AS Id FROM Person GROUP BY Email HAVING COUNT(Email) > 1;
SELECT t.Id FROM (SELECT MIN(Id) AS Id FROM Person GROUP BY Email) t;

-- @lc code=start
# Write your MySQL query statement below
DELETE FROM Person WHERE Id NOT IN (
  SELECT t.Id FROM (SELECT MIN(Id) AS Id FROM Person GROUP BY Email) t);

-- @lc code=end
SELECT * FROM Person;

.quit
