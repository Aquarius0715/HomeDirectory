use crate::schema::person_data;
use crate::schema::login_data;
use crate::schema::smass_config;

#[derive(Insertable)]
#[table_name = "person_data"]
pub struct InsertPersonData {
    pub uuid: String,
    pub family_uuid: String,
    pub sex: i8,
    pub first_name: String,
    pub last_name: String,
    pub birth_day: String,
    pub phone_number: String,
    pub tel_number: String,
    pub others: String
}

#[derive(Debug, Queryable)]
pub struct PersonData {
    pub id: u64,
    pub uuid: String,
    pub family_uuid: String,
    pub sex: i8,
    pub first_name: String,
    pub last_name: String,
    pub birth_day: String,
    pub phone_number: String,
    pub tel_number: String,
    pub others: String
}

#[derive(Insertable)]
#[table_name = "login_data"]
pub struct InsertLoginData {
    pub login_id: String,
    pub login_password: String,
    pub permission: String
}

#[derive(Debug, Queryable)]
pub struct LoginData {
    pub id: u64,
    pub login_id: String,
    pub login_password: String,
    pub permission: String
}

#[derive(Insertable)]
#[table_name = "smass_config"]
pub struct InsertSmassConfig {
    pub is_first_run: i8
}

#[derive(Debug, Queryable)]
pub struct SmassConfig {
    pub id: u64,
    pub is_first_run: i8
}