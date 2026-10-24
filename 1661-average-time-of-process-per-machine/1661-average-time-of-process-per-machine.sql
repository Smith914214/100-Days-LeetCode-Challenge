# Write your MySQL query statement below
# Write your MySQL query statement below

 select machine_id ,

 Round(

    ( sum(case when activity_type = 'end' then timestamp else 0 end) - 
     sum(case when activity_type = 'start' then timestamp else 0 end) ) / (count(*)/2)
     

     ,3
 ) as processing_time

 from activity
 group by machine_id;