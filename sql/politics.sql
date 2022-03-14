CREATE TABLE IF NOT EXISTS country (
    id int(11) PRIMARY KEY NOT NULL,
    name text NOT NULL
);

CREATE TABLE IF NOT EXISTS presidents (
    id int(11) NOT NULL,
    name text NOT NULL,
    country_id int(11) NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE KEY country_id (country_id),
    CONSTRAINT presidents_ibfk_1 FOREIGN KEY (country_id) REFERENCES country (id)
);
