--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

# cat 197.rising-temperature.sql |  sqlite3 -batch
.header on
CREATE TABLE Weather (id int, recordDate date, temperature int);
INSERT INTO Weather VALUES (1, "2015-01-01", 10);
INSERT INTO Weather VALUES (2, "2015-01-02", 25);
INSERT INTO Weather VALUES (3, "2015-01-03", 20);
INSERT INTO Weather VALUES (4, "2015-01-04", 300);
SELECT * FROM Weather;

-- @lc code=start
# Write your MySQL query statement below
SELECT id FROM Weather W1
WHERE temperature > (SELECT temperature FROM Weather W2 WHERE TO_DAYS(W1.recordDate) - TO_DAYS(W2.recordDate) = 1);
-- @lc code=end

.quit
