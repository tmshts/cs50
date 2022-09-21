SELECT p.name FROM people p
WHERE p.id IN (
SELECT s.person_id FROM stars s
WHERE s.movie_id IN (
SELECT m.id FROM movies m
WHERE m.year = 2004))
ORDER BY p.birth ASC;