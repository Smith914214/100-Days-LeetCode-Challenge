# Write your MySQL query statement below
SELECT Tweet_id
FROM Tweets
WHERE char_length(content) > 15;