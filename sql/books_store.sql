CREATE TABLE IF NOT EXISTS authors (
    id int(11) NOT NULL,
    name text NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS books (
    id int(11) NOT NULL,
    name text NOT NULL,
    author_id int(11) DEFAULT NULL,
    PRIMARY KEY (id),
    KEY author_id (author_id),
    CONSTRAINT books_ibfk_1 FOREIGN KEY (author_id) REFERENCES authors (id)
)l
