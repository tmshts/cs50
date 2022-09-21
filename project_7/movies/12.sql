SELECT m.title FROM movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p ON s.person_id = p.id
WHERE s.movie_id IN (
SELECT s.movie_id FROM stars s
JOIN people p ON s.person_id = p.id
WHERE p.name = "Helena Bonham Carter") AND p.name = "Johnny Depp";