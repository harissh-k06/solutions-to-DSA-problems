# Write your MySQL query statement below
SELECT tweet_id from Tweets where 
CHAR_LENGTH (CONTENT) > 15;