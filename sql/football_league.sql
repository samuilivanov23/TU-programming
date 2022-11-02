CREATE DATABASE IF NOT EXISTS football_league;

USE football_league;

CREATE TABLE IF NOT EXISTS clubs(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    name CHAR(100) NOT NULL,
    points INT NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS matches(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    hostID BIGINT NOT NULL,
    guestID BIGINT NOT NULL,
    UNIQUE KEY(hostID, guestID),
    CONSTRAINT FOREIGN KEY (hostID) REFERENCES clubs(id),
    CONSTRAINT FOREIGN KEY (guestID) REFERENCES clubs(id),
    hostGoals INT DEFAULT NULL,
    guestGoals INT DEFAULT NULL
);

INSERT INTO clubs (name) VALUES('Manchester United');
INSERT INTO clubs (name) VALUES('Levski');
INSERT INTO clubs (name) VALUES('Botev Plovdiv');

INSERT INTO matches (hostID, guestID) SELECT c2.id, c1.id FROM clubs AS c1 CROSS JOIN clubs AS c2 WHERE c2.id<>c1.id;

DELIMITER |

CREATE TRIGGER AssignPointsToClubs AFTER UPDATE ON matches
FOR EACH ROW
    BEGIN
        IF(NEW.hostGoals=NEW.guestGoals) THEN
            UPDATE clubs SET points=points+1 WHERE id=NEW.hostID OR id=NEW.guestID;
        ELSEIF(NEW.hostGoals>NEW.guestGoals) THEN
            UPDATE clubs SET points=points+3 WHERE id=NEW.hostID;
        ELSE
            UPDATE clubs SET points=points+3 WHERE id=NEW.guestID;
        END IF;
    END;
|

DELIMITER ;



