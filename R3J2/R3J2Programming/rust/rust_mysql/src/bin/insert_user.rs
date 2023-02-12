use diesel::pg::types::sql_types::Uuid;
use diesel::prelude::*;
use rust_mysql::models::InsertPersonData;
use rust_mysql::schema::users;
use rust_mysql::utils::establish_connection;
use uuid::uuid;

fn main() {
    let connection = establish_connection();
    let new_user = InsertPersonData {
        uuid: Uuid::new_v4()?,
        family_uuid: "".to_string(),
        sex: 0,
        first_name: "".to_string(),
        last_name: "".to_string(),
        birth_day: "".to_string(),
        phone_number: "".to_string(),
        tel_number: "".to_string(),
        others: "".to_string()
    };
    diesel::insert_into(users::dsl::users)
        .values(new_user)
        .execute(&connection)
        .expect("Error saving new user");
}