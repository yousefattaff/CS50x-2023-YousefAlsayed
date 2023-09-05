SELECT DISTINCT p2.name FROM people p2
JOIN stars s2 ON p2.id = s2.person_id
JOIN movies m ON s2.movie_id = m.id
WHERE m.id IN (
    SELECT m.id FROM movies m
    JOIN stars s1 ON m.id = s1.movie_id
    JOIN people p1 ON s1.person_id = p1.id
    WHERE p1.name = 'Kevin Bacon' AND p1.birth = 1958
) AND p2.name != 'Kevin Bacon';