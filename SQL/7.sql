select department_id, count(*) from employees group by department_id having count(*) > 10 order by 2

