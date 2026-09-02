# Write your MySQL query statement below
SELECT DISTINCT author_id as id from Views as v where 
v.author_id = v.viewer_id ORDER BY id ASc