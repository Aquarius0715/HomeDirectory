use diesel::prelude::*;
use rust_mysql::schema::users;
use rust_mysql::utils::establish_connection;

fn main() {
    let connection = establish_connection();
    diesel::delete(users::dsl::users.filter(users::name.eq("Masaki Kitano")))
        .execute(&connection)
        .expect("Error deleting users");
}