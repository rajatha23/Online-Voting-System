#Online Voting System

A web-based Online Voting System developed as a Data Structures and Algorithms (DSA) Mini Project. The system allows voters to cast votes securely using a unique voter ID while preventing duplicate voting. Candidate information and vote counts are managed efficiently using a Binary Search Tree (BST).

---

##Team Members

- Rajatha Shetty
- Sandhya S
- Moksha



##Project Description

The Online Voting System is designed to provide a secure, efficient, and user-friendly voting platform. The application validates voter IDs, prevents duplicate voting, records votes, and displays election results accurately.

The project demonstrates the practical application of Data Structures and Algorithms by using a Binary Search Tree (BST) to store candidate information and manage vote counts efficiently.

---

##Objectives

- Develop a secure online voting platform.
- Validate voters using a unique voter ID.
- Prevent duplicate voting.
- Store candidate information efficiently.
- Count votes accurately using Data Structures.
- Generate quick and transparent election results.
- Demonstrate real-world application of DSA concepts.

---

##Features

### Voter Module
- Enter Voter ID
- Cast vote securely
- One vote per voter
- Instant vote confirmation

### Admin Module
- Admin login access
- View election results
- Monitor voting status

### System Features
- Candidate management using BST
- Duplicate vote prevention
- Efficient vote counting
- User-friendly interface

---

##Technologies Used

### Frontend
- HTML5
- CSS3

### Backend
- C Programming
- CGI (Common Gateway Interface)

### Server
- XAMPP
- Apache Web Server

### Data Structures
- Binary Search Tree (BST)
- Arrays
- Structures

---

##Data Structure Used

### Binary Search Tree (BST)

BST is used to store candidate information and vote counts.

#### Operations
- Candidate Insertion
- Candidate Search
- Vote Count Update
- Result Display

#### Advantages
- Efficient searching
- Faster updates
- Organized storage
- Better performance

---

##System Workflow

1. User enters Voter ID.
2. System validates the voter.
3. System checks whether the voter has already voted.
4. Candidate list is displayed.
5. User selects a candidate.
6. Vote is recorded.
7. BST updates vote count.
8. Confirmation message is displayed.
9. Admin can view results.

---

##Project Structure

```text
Online-Voting-System/
│
├── index.html
├── admin.html
├── login.cgi
├── vote.cgi
├── result.cgi
├── style.css
└── voting.c
```

---

##Installation & Setup

### Prerequisites

- XAMPP
- Apache Server
- GCC Compiler
- Web Browser

### Steps

1. Install XAMPP.
2. Start Apache Server.
3. Place HTML files inside:

```text
xampp/htdocs/
```

4. Place CGI files inside:

```text
xampp/cgi-bin/
```

5. Compile the C source file:

```bash
gcc voting.c -o voting.cgi
```

6. Open browser and run:

```text
http://localhost/index.html
```

---

##Time Complexity

| Operation | Complexity |
|------------|------------|
| Search Candidate | O(log n) |
| Insert Candidate | O(log n) |
| Update Vote | O(log n) |
| Display Results | O(n) |

*Average case complexity for BST.*

---

##Impact Analysis

- Improved understanding of Binary Search Trees through practical implementation.
- Enhanced C programming and problem-solving skills.
- Learned frontend and backend integration using HTML, CSS, and CGI.
- Gained experience in developing real-world web applications.
- Improved teamwork and project coordination.
- Developed knowledge of secure voting mechanisms.

---

##Future Enhancements

- Database integration using MySQL.
- OTP-based voter verification.
- Improved security mechanisms.
- Real-time result dashboard.
- Mobile-responsive interface.
- Cloud deployment support.

---

## Conclusion

The Online Voting System successfully demonstrates the practical implementation of Data Structures and Algorithms in a real-world application. By utilizing a Binary Search Tree for candidate management and vote counting, the system ensures efficient operations and reliable performance. The project provides a secure and user-friendly voting environment while preventing duplicate voting and maintaining election integrity.

---

##References

1. Data Structures and Algorithms Course Notes
2. C Programming Documentation
3. HTML & CSS Documentation
4. Apache CGI Documentation
5. XAMPP Documentation
6. W3Schools
7. MDN Web Docs

---

© 2025 Rajatha Shetty, Sandhya S, Moksha  
Department of Information Science & Engineering  
Sahyadri College of Engineering & Management, Mangaluru
