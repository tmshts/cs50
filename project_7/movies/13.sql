SELECT DISTINCT(p.name) FROM people p
JOIN stars s ON p.id = s.person_id
WHERE p.name NOT LIKE "Kevin Bacon" AND s.movie_id IN (
SELECT s.movie_id FROM stars s
WHERE s.person_id IN (SELECT p.id FROM people p
WHERE p.name = "Kevin Bacon" AND p.birth = 1958))