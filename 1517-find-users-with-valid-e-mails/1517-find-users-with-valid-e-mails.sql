# Write your MySQL query statement below
SELECT * from Users
where mail regexp  '^[a-zA-Z][a-zA-Z_0-9.-]*@leetcode[.]com$' and mail like BINARY '%@leetcode.com';