document.addEventListener("DOMContentLoaded", function() {
    // Navigation active class
    const navLinks = document.querySelectorAll(".nav-link");
    navLinks.forEach(link => {
        link.addEventListener("click", function() {
            navLinks.forEach(navLink => {
                navLink.classList.remove("active");
            });
            this.classList.add("active");
        });
    });

    // Contact form submission
    const contactForm = document.querySelector(".contact-form");
    contactForm.addEventListener("submit", function(event) {
        event.preventDefault();
        const name = document.querySelector("#name").value;
        const email = document.querySelector("#email").value;
        const message = document.querySelector("#message").value;

        // Perform form validation and send data to server (simulated here)
        if (name && email && message) {
            alert("Form submitted successfully!");
            this.reset();
        } else {
            alert("Please fill in all fields.");
        }
    });
});
