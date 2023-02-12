use diesel::prelude::*;
use rust_mysql::schema::users;
use rust_mysql::utils::establish_connection;

fn main() {
    let connection = establish_connection();
    diesel::update(users::dsl::users.filter(users::name.eq("Masaki Kitano")))
        .set(users::name.eq("updated"))
        .execute(&connection)
        .expect("Error updating users");
}