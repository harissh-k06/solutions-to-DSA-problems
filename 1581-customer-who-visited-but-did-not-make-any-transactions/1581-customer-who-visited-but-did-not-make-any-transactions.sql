# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.visit_id) as count_no_trans From VISITS as v LEFT JOIN Transactions as t
 on t.visit_id = v.visit_id where t.transaction_id  IS NULL GROUP BY v.customer_id 