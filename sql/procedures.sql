/* 1 */
DELIMITER |

CREATE PROCEDURE SelectAllCities( IN population INT)
BEGIN
    SELECT * FROM city as c where c.population>@population;
END;
|

DELIMITER ;

SET @population = 100000;
CALL SelectAllCities();

/* 2 */
DELIMITER |

CREATE PROCEDURE SelectAllFromContinent( IN continent CHAR(100) )
BEGIN
    SELECT * from country as c where c.continent=@continent;
END;
|

DELIMITER ;

SET @continent='Africa';
CALL SelectAllFromContinent( @continent );

/* 3 */
DELIMITER |

CREATE PROCEDURE GetContinentCountriesCount( IN continent CHAR(100), OUT country_count INT )
BEGIN
    SELECT COUNT(*) INTO country_count from country as c where c.continent=continent;
END;
|

DELIMITER ;

SET @continent = 'Europe';
SET @country_count = 0;
SELECT @country_count;
CALL GetContinentCountriesCount( @continent, @country_count );
SELECT @country_count;

/* 1 FROM FILE */
DELIMITER |

CREATE PROCEDURE GetCountryCapital( IN country_name CHAR(100), OUT country_capital CHAR(100) )
BEGIN
    SELECT ci.Name INTO country_capital FROM country as co JOIN city as ci ON co.Capital=ci.id where co.Name=country_name;
END;
|

DELIMITER ;

SET @country_name = 'Bulgaria';
SET @capital_name = 'None';
SELECT @capital_name;
CALL GetCountryCapital( @country_name, @capital_name );
SELECT @capital_name;

/* 2 FROM FILE */
DELIMITER |

CREATE PROCEDURE HighestAvgLifetimeInContinent( IN country_name CHAR(100), OUT result INT )
BEGIN
   SELECT COUNT(*) INTO result FROM country AS co WHERE co.LifeExpectancy > ( SELECT AVG(co2.LifeExpectancy) FROM country AS co2 GROUP BY co2.Continent HAVING co2.Continent=co.Continent ) AND co.Name=country_name; 
END;
|

DELIMITER ;

SET @country_name = 'Kenya';
SET @result = -1;
CALL HighestAvgLifetimeInContinent( @country_name, @result );
SELECT @result;


/* 3 FROM FILE */

DELIMITER |

CREATE PROCEDURE GetCountryIncomeLevel( IN country_name CHAR(100), OUT income_result CHAR(30) )
BEGIN
    DECLARE tmpGNP decimal;

    SELECT co.GNP INTO tmpGNP FROM (SELECT GNP FROM country AS co WHERE co.Name=country_name) as co;

    IF tmpGNP > 12695 THEN 
        SET income_result = 'High income'; 
    ELSEIF tmpGNP >= 4096 AND tmpGNP < 12695 THEN 
        SET income_result = 'Upper-middle income'; 
    ELSEIF tmpGNP >= 1046 AND tmpGNP < 4096 THEN 
        SET income_result = 'Lower-middle income';
    ELSE SET 
        income_result = 'Low income';
    
    END IF;   
END;
|

DELIMITER ;

SET @country_name = 'Germany';
SET @income_result = 'None';
CALL GetCountryIncomeLevel( @country_name, @income_result );
SELECT @income_result;

/* 4 FROM FILE */
DELIMITER |

CREATE PROCEDURE IncreaseGnpOld( IN region CHAR(30) )
BEGIN
    DECLARE finished INT;
    DECLARE tmpCode CHAR(10);
    
    DECLARE GnpOldCursor CURSOR FOR
    SELECT Code FROM country as co WHERE co.Region = region;

    DECLARE CONTINUE handler FOR NOT FOUND SET finished = 1;
    SET finished = 0;

    OPEN GnpOldCursor;
    gnpold_loop : WHILE( finished = 0 )
    DO
        FETCH GnpOldCursor INTO tmpCode;
        IF( finished = 1 ) THEN
            LEAVE gnpold_loop;
        END IF;
        UPDATE country as co SET co.GNPOld = co.GNPOld + 0.02*co.GNPOld WHERE co.Code = tmpCode;
    END WHILE;
END;
|

DELIMITER ;

SET @country_region = 'South America';
CALL IncreaseGnpOld( @country_region );
SELECT * FROM country WHERE Region = @country_region;


