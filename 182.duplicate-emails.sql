--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--

# cat 182.duplicate-emails.sql |  sqlite3 -batch
.header on
CREATE TABLE Person (Id int, Email string);
INSERT INTO Person VALUES (1, "a@b.com");
INSERT INTO Person VALUES (2, "c@d.com");
INSERT INTO Person VALUES (3, "a@b.com");
SELECT * FROM Person;

-- @lc code=start
# Write your MySQL query statement below

SELECT Email FROM Person GROUP BY Email HAVING COUNT(Email) > 1;

-- @lc code=end

.quit
