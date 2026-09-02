# Write your MySQL query statement below
SELECT w1.id from weather as w1 LEFT JOIN weather as w2 ON w1.recordDate - INTERVAL 1 DAY = w2.recordDate where w1.temperature   > w2.temperature   