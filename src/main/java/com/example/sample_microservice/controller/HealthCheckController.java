package com.example.sample_microservice.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HealthCheckController {
    
    @GetMapping("/health-2")
    public String healthCheck() {
        // Returning a simple status message
        return "Service is healthy";
    }
}