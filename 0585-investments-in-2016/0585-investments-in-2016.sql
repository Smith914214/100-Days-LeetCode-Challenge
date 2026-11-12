# Write your MySQL query statement below
WITH Counts AS (
    SELECT 
        tiv_2016,
        -- Count how many times this tiv_2015 appears in the whole table
        COUNT(tiv_2015) OVER(PARTITION BY tiv_2015) as tiv_count,
        -- Count how many times this specific location appears
        COUNT(lat) OVER(PARTITION BY lat, lon) as loc_count
    FROM 
        insurance
)
SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM 
    Counts
WHERE 
    tiv_count > 1    -- Must share tiv_2015 with at least one other person
    AND loc_count = 1; -- Must be the only person at this location
    