


import Foundation

class AuthenticationVM{
    var user: User!
    
    var phonenumber: String {
        return user.phonenumber
    }
    var code: String {
        return user.code
    }
    
}
