-- Your SQL goes here

CREATE TABLE IF NOT EXISTS person_data
(
    id SERIAL,
    uuid VARCHAR(36) NOT NULL DEFAULT 'unknown' PRIMARY KEY,
    family_uuid VARCHAR(36) NOT NULL DEFAULT 'unknown',
    sex TINYINT NOT NULL DEFAULT -1,
    first_name VARCHAR(32) NOT NULL DEFAULT 'unknown',
    last_name VARCHAR(32) NOT NULL DEFAULT 'unknown',
    birth_day VARCHAR(8) NOT NULL DEFAULT 'unknown',
    phone_number VARCHAR(11) NOT NULL DEFAULT 'unknown',
    tel_number VARCHAR(10) NOT NULL DEFAULT 'unknown',
    others VARCHAR(256) NOT NULL DEFAULT 'none'
);

CREATE TABLE IF NOT EXISTS login_data
(
    id SERIAL PRIMARY KEY,
    login_id VARCHAR(32) NOT NULL DEFAULT 'unknown',
    login_password VARCHAR(32) NOT NULL DEFAULT 'unknown',
    permission VARCHAR(32) NOT NULL DEFAULT 'unknown'
);

CREATE TABLE IF NOT EXISTS smass_config
(
    id SERIAL PRIMARY KEY,
    is_first_run TINYINT NOT NULL DEFAULT 0
);