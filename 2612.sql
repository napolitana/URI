SELECT DISTINCT movies.id, movies.name 
FROM movies, movies_actors, actors, genres 
WHERE (actors.name= 'Marcelo Silva' OR actors.name= 'Miguel Silva') AND movies_actors.id_actors = actors.id AND movies_actors.id_movies=movies.id AND movies.id_genres=genres.id AND genres.description='Action'
