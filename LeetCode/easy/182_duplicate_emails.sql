select distinct
    Person.email as Email
from Person
    join (
        select
            email,
            count(email) as num
        from Person
        group by
            email
    ) AggPerson on Person.email = AggPerson.email
where
    AggPerson.num > 1

-- Another solution
-- SELECT p2.email FROM Person p2 GROUP BY p2.email having count(*) > 1

-- Another solution
-- select
--     email as Email
-- from person
-- group by
--     email
-- having
--     count(*) > 1
