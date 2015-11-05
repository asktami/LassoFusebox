CREATE TABLE IF NOT EXISTS people (
id mediumint NOT NULL AUTO_INCREMENT PRIMARY KEY,
first_name varchar(255),
last_name varchar(255),
company varchar(255),
phone_number varchar(255),
title ENUM('Mr.', 'Mrs.', 'Ms.', 'Dr.'),
sex ENUM('Male', 'Female'),
jobs varchar(255),
txt VARCHAR(45) NOT NULL,
dateCreated DATETIME NOT NULL,
nbr INT UNSIGNED
) ENGINE=MyISAM;