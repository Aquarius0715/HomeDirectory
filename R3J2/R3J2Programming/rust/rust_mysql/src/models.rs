use diesel::RunQueryDsl;
use crate::schema::person_data::dsl::person_data;
use crate::utils::establish_connection;

#[derive(Insertable)]
#[table_name = "person_data"]
pub struct PersonData {
    pub uuid: String,
    pub family_uuid: String,
    pub sex: i8,
    pub first_name: String,
    pub last_name: String,
    pub birth_day: String,
    pub phone_number: String,
    pub tel_number: String,
    pub others: String,
}

#[derive(Debug, Queryable)]
pub struct User {
    pub id: u64,
    pub uuid: String,
    pub family_uuid: String,
    pub sex: i8,
    pub first_name: String,
    pub last_name: String,
    pub birth_day: String,
    pub phone_number: String,
    pub tel_number: String,
    pub others: String,
}