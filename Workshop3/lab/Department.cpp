#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds
{
    Department::Department()
    {
        m_name = nullptr;
        m_project = nullptr;
        m_projCount = 0;
        m_budget = 15345.99;
    }
    // fully provided for students to display details of a project
    void display(const Project &project)
    {
        cout << "Project " << project.m_topic
             << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    // fully provided for students to display details of a department
    void display(const Department &department)
    {
        Project *temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
             << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++)
        {
            display(temp[i]);
        }
    }

    void Department::updateName(const char *newname)
    {
        if (newname != nullptr)
        {
            if (m_name != nullptr)
            {
                delete[] m_name;
                m_name = nullptr;
            }
            m_name = new char[strlen(newname) + 1];
            strcpy(m_name, newname);
        }
    }
    void Department::updateBudget(double change)
    {
        m_budget += change;
    }
    bool Department::addProject(Project &newproject)
    {
        bool status = false;
        if (totalexpenses() + newproject.m_cost < fetchBudget())
        {
            // add newproject to department list of projects
            Project *temp = new Project[m_projCount + 1];

            for (int i = 0; i < m_projCount; i++)
            {
                temp[i] = m_project[i];
            }
            temp[m_projCount] = newproject;
            delete[] m_project;
            m_project = nullptr;
            m_projCount++;
            // m_project = new Project[m_projCount];
            m_project = temp;
            // delete[] temp;
            // temp = nullptr;
            status = true;
        }
        return status;
    }
    void Department::createDepartment(const char *newname, Project &newproject, double change)
    {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }
    Project *Department::fetchProjects() const
    {
        return m_project;
    }
    int Department::fetchNumProjects() const
    {
        return m_projCount;
    }
    double Department::fetchBudget() const
    {
        return m_budget;
    }
    char *Department::fetchName() const
    {
        return m_name;
    }
    double Department::totalexpenses()
    {
        double total = 0.0;
        for (int i = 0; i < m_projCount; i++)
        {
            total += m_project[i].m_cost;
        }
        return total;
    }
    double Department::remainingBudget()
    {
        return m_budget - totalexpenses();
    }
    void Department::clearDepartment()
    {
        delete[] m_name;
        m_name = nullptr;
        delete[] m_project;
        m_project = nullptr;
        m_projCount = 0;
        m_budget = 0;
    }
}