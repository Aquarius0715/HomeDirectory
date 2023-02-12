-- Your SQL goes here
CREATE TABLE IF NOT EXISTS person_data
(
    id SERIAL PRIMARY KEY,
    uuid VARCHAR(36) NOT NULL DEFAULT 'unknown',
    family_uuid VARCHAR(36) NOT NULL DEFAULT 'unknown',
    sex TINYINT NOT NULL DEFAULT -1,
    first_name VARCHAR(32) NOT NULL DEFAULT 'unknown',
    last_name VARCHAR(32) NOT NULL DEFAULT 'unknown',
    birth_day VARCHAR(8) NOT NULL DEFAULT 'unknown',
    phone_number VARCHAR(11) NOT NULL DEFAULT 'unknown',
    tel_number VARCHAR(10) NOT NULL DEFAULT 'unknown',
    others VARCHAR(256) NOT NULL DEFAULT 'none'
);