SELECT DISTINCT(p.name) FROM people p
JOIN directors d ON p.id = d.person_ID
WHERE d.person_id IN (
SELECT d.person_id FROM directors d
JOIN movies m ON d.movie_id = m.id
WHERE m.id IN (
SELECT m.id FROM movies m
JOIN ratings r ON m.id = r.movie_id
WHERE r.rating >= 9.0))