/* Task 1 */
CREATE TABLE IF NOT EXISTS LogCity (
  id int(11) PRIMARY KEY AUTO_INCREMENT,
  updated_at TIMESTAMP NOT NULL DEFAULT NOW(),
  old_Name char(35) NOT NULL DEFAULT '',
  new_Name char(35) NOT NULL DEFAULT '',
  old_CountryCode char(3) NOT NULL DEFAULT '',
  new_CountryCode char(3) NOT NULL DEFAULT '',
  old_District char(20) NOT NULL DEFAULT '',
  new_District char(20) NOT NULL DEFAULT '',
  old_Population int(11) NOT NULL DEFAULT 0,
  new_Population int(11) NOT NULL DEFAULT 0
);


DELIMITER |

CREATE TRIGGER after_city_update AFTER UPDATE ON city 
FOR EACH ROW 
    BEGIN
        INSERT INTO LogCity(old_Name,
            new_Name, 
            old_CountryCode, 
            new_CountryCode, 
            old_District, 
            new_District, 
            old_Population, 
            new_Population) 
        VALUES ('UPDATE', 
            OLD.Name, 
            CASE NEW.Name WHEN OLD.Name THEN NULL ELSE NEW.Name END,
            OLD.CountryCode, 
            CASE NEW.CountryCode WHEN OLD.CountryCode THEN NULL ELSE NEW.CountryCode END, 
            OLD.District, 
            CASE NEW.District WHEN OLD.District THEN NULL ELSE NEW.District END, 
            OLD.Population, 
            CASE NEW.Population WHEN OLD.Population THEN NULL ELSE NEW.Population END); 
    END;
|

DELIMITER ;


/* Task 2 and 3 */

DELIMITER |

CREATE TRIGGER before_city_insert BEFORE INSERT ON city 
FOR EACH ROW 
    BEGIN
       DECLARE err_message varchar(255);
       IF (NEW.Population < 0) THEN 
            SET err_message='ERROR_MESSAGE|||Population must not be negative!'; 
            signal sqlstate '45000' set message_text = err_message;
       END IF;
    END;
|

DELIMITER ;


/* Task 4 */

DROP TRIGGER before_city_insert_check_codes;

DELIMITER |

CREATE TRIGGER before_city_insert_check_codes BEFORE INSERT ON city 
FOR EACH ROW 
    BEGIN
       DECLARE err_message varchar(255);
       IF (SELECT NEW.CountryCode NOT IN (SELECT DISTINCT c.CountryCode FROM city AS c) AS my_country) THEN 
            SET err_message='ERROR_MESSAGE|||Population must not be negative!'; 
            signal sqlstate '45000' SET message_text = err_message;
       END IF;
    END;
|

DELIMITER ;

